#include <SDL2/SDL.h>
#include <numeric>
#include <complex>

int zoom = 1;
int pixelShift_X = 0;
int pixelShift_Y = 0;

int isInSet(std::complex<double> c) {

    std::complex<double> z(0,0);

    for (int i = 0; i < 250; i++) {
        z = std::pow(z, 2) + c;
        if (std::norm(z) > 10) {
            return i;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (zoom < 1) {
        zoom = 1;
    }
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(2000, 2000, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);

    for (double x = 0.0; x < 1.0; x += 0.001)
        for (double y = 0.0; y < 1.0; y += 0.001) {
            double pointX = std::lerp(-2.0, 2.0, (x - pixelShift_X) / zoom);
            double pointY = std::lerp(-2.0, 2.0, (y - pixelShift_Y) / zoom);
            int iters = isInSet(std::complex<double>(pointX, pointY));
            if (iters == 0) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
            } else {
                SDL_SetRenderDrawColor(renderer,
                                       8 * iters % 255,
                                       9 * iters % 255,
                                       10 * iters % 255,
                                       255);
                SDL_RenderDrawPointF(renderer, x * 1000, y * 1000);
            }
        }
    SDL_RenderPresent(renderer);
    SDL_Delay(1000);

    return 0;
}