#include "Game.h" 

Game::Game() : isRunning(false), window(nullptr), renderer(nullptr) {}

Game::~Game() {}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_VIDEO) == 0) {
        std::cout<< "SDL initializat!\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window) {
            std::cout << "Fereastra creata!\n";
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            std::cout << "Renderer creat!\n";
        }

        isRunning = true;
    } else {
        std::cerr << "Eroare la SDL_Init: " << SDL_GetError() << '\n';
        isRunning = false;
    }

    return isRunning;
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update() {
    //logica ulterioara
}

void Game::render() {
    SDL_RenderClear(renderer);
    //
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "closing...\n";
}

