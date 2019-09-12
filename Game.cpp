#include "Game.h"
using namespace std;

//This is the game controller class.


//Pointers declared.
Player* player;
Enemy* enemy;
Enemy* henchmen;
Balochistan* background;
Weapons* gun;
Bullet* bullet;

//Variables Declared
int level = 1;
double change = 0.0222;
double angle = change;
bool weapon_active = false;
bool bullet_active = false;
bool bullet_pro_active = false;
bool enemy_alive = true;
bool henchmen_alive = true;


SDL_Renderer* Game::renderer = nullptr;

//No need for constructor.
Game::Game(){}
Game::~Game(){}


//Is called to initiate the game sequence.
void Game::inint(const char* title, int xpos, int ypos, int width, int height)
{
    int flag = 0;
    
    //Creating window and renderer.
    //Checks included for easier debugging.
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "Subsytems initialized!!" << endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        
        if (window)
        {
            cout << "Window created!" << endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer created!" << endl;
        }
        
        isrunning = true;
        
        //Audio added using SDL_Mixer.
        if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
        {
            std::cout << "Problems!!!!" << std::endl;
        }
        
        music = Mix_LoadMUS("Water.mp3");
        jump = Mix_LoadWAV("Banana.wav");
    }
    else
    {
        isrunning = false;
    }
    
    //Creation of objects - player, enemy and background.
    background = new Balochistan("Morning.png");
    player = new Player("Player.png", 0, 550, 80, 110);
    enemy = new Enemy("Venom.png", 800, 600, 29, 47);
    henchmen = new Enemy("Thanos.png", 1275, 600, 29, 47);
    Mix_PlayMusic(music, -1);
}

//Handles what goes on during the game.
void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isrunning = false;
            break;
        default:
            break;
    }
    
    //Gives the player a weapon after moving 200 units.
    if (player->get_xpos() > 200)
    {
        gun = new Weapons("Gun.png", (player->get_xpos()+30), (player->get_ypos()+50));
        weapon_active = true;
    }
    else
    {
        weapon_active = false;
    }
    
    //To make the player move.
    //Keep track of keydown events.
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_RIGHT)
        {
            player->set_xpos(player->get_xpos() + 10);
            if (weapon_active)
            {
                gun->set_xpos(player->get_xpos()+10);
            }
            player->set_animate(true);
        }
        else
        {
            player->set_animate(false);
        }
        
        if (event.key.keysym.sym == SDLK_LEFT)
        {
            player->set_xpos(player->get_xpos() - 10);
            player->set_animate(true);
        }
        
        if (event.key.keysym.sym == SDLK_f && weapon_active)
        {
            bullet = new Bullet("Bullet.png", (player->get_xpos()+20), (player->get_ypos()+50));
            bullet_active = true;
        }
        
        if (event.key.keysym.sym == SDLK_p && weapon_active)
        {
            bullet = new Bullet("Bullet.png", (player->get_xpos()+20), (player->get_ypos()+50));
            bullet_pro_active = true;
        }
        
        if (event.key.keysym.sym == SDLK_SPACE)
        {
            player->set_animate(true);
            player->set_jump(true);
        }
    }
    
    //Stop player animation.
    if (event.type == SDL_KEYUP)
    {
        player->set_animate(false);
    }
    
    //Linear motion of the enemy.
    if (enemy_alive)
    {
        enemy->set_xpos(enemy->get_xpos() - 0.5);
    }
    
    if (henchmen_alive)
    {
        henchmen->set_xpos(henchmen->get_xpos() - 0.5);
    }
    
    
    //Linear motion of the bullet.
    if (bullet_active)
    {
        bullet->xpos += 10;
    }
    //Collision Detetction.
    if (enemy_alive)
    {
        if (SDL_HasIntersection(&player->destR, &enemy->destR) == true)
        {
            player->set_xpos(player->get_xpos() - 2);
        }
    }
    
    if (henchmen_alive)
    {
        if (SDL_HasIntersection(&player->destR, &henchmen->destR) == true)
        {
            player->set_xpos(player->get_xpos() - 2);
        }
    }
    
    
    if (bullet_active)
    {
        if (SDL_HasIntersection(&bullet->destR, &enemy->destR) == true)
        {
            delete bullet;
            bullet_active = false;
            delete enemy;
            enemy_alive = false;
        }
    }
    
    if (bullet_active)
    {
        if (SDL_HasIntersection(&bullet->destR, &henchmen->destR) == true)
        {
            delete bullet;
            bullet = nullptr;
            bullet_active = false;
            
            delete henchmen;
            henchmen = nullptr;
            henchmen_alive = false;
        }
    }
    
    //Level 1 changes
    if (level == 1 && player->get_xpos() > 1280)
    {
        
        delete background;
        background = new Balochistan("Shaam.png");
        enemy = new Enemy("Hulk.png", 800, 600, 36, 54);
        henchmen = new Enemy("idk.png", 1275, 600, 53, 57);
        enemy_alive = true;
        henchmen_alive = true;
        player->set_xpos(0);
        player->set_ypos(550);
        level++;
    }
    
    //Level 2 changes
    if (level == 2 && player->get_xpos() > 1280)
    {
        delete background;
        background = new Balochistan("Afternoon.png");
        enemy = new Enemy("Magneto.png", 800, 600, 30, 46);
        henchmen = new Enemy("Green Goblin.png", 1275, 600, 56, 46);
        enemy_alive = true;
        henchmen_alive = true;
        player->set_xpos(0);
        player->set_ypos(550);
        level++;
    }
    
    //Level 3 changes
    if (level == 3 && player->get_xpos() > 1280)
    {
        delete background;
        background = new Balochistan("Night.png");
        enemy = new Enemy("RedHulk.png", 800, 600, 34, 50);
        henchmen = new Enemy("Juggernaut.png", 1275, 600, 53, 55);
        enemy_alive = true;
        henchmen_alive = true;
        player->set_xpos(0);
        player->set_ypos(550);
        level++;
    }
    
    //Deleting bullet.
    if (bullet_active && bullet->xpos > 1280)
    {
        delete bullet;
        bullet = nullptr;
        bullet_active = false;
    }

    //Deleting the player
    if (level == 4 && player->get_xpos() > 1280)
    {
        std::cout<<"Player deleted and gun"<<std::endl;
        delete gun;
        gun = nullptr;
        
        delete player;
        player = nullptr;
        
        clean();
    }
}

//Renders all object onto the screen.
void Game::render(long long int frame)
{
    SDL_RenderClear(renderer);
    
    //Rendering the background.
    background->DrawMap();
    
    //Making the player jump in a projectile.
    if (player->get_jump())
    {
        player->set_ypos(player->get_ypos() - sin(angle));
        player->set_xpos(player->get_xpos() + 1);
        
        gun->set_ypos(player->get_ypos() - sin(angle));
        gun->set_xpos(player->get_xpos() + 1);
        
        angle += change;
    }
    
    //Making the bullet move in a projectile.
    if (bullet_pro_active)
    {
        bullet->xpos -= sin(angle);
        //player->set_xpos(player->get_xpos() + 1);
    }
    
    //Setting upper limit to player jump.
    if (player->get_ypos() >= 550)
    {
        player->set_jump(false);
    }
    
    player->Render(frame);
    
    if (enemy_alive)
    {
        enemy->Render(frame);
    }
    
    if (henchmen_alive)
    {
        henchmen->Render(frame);
    }
    
    //shows weapon when active.
    if (weapon_active)
    {
        gun->Render();
    }
    //Shows bullet when active.
    if (bullet_active)
    {
        bullet->Render();
    }
    
    SDL_RenderPresent(renderer);
}

//Clears screen once game is quitted.
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    Mix_FreeChunk(jump);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    cout << "Game cleaned" << endl;
}

//Updates the status of the player, enemy, henchmen and bullet.
void Game::update()
{
    player->Update();
    
    if (enemy_alive)
    {
        enemy->Update();
    }
    
    if (henchmen_alive)
    {
        henchmen->Update();
    }
    
    if (bullet_active)
    {
        bullet->Update();
    }
}




