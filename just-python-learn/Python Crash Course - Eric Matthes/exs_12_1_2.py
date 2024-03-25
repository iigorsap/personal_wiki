# Exercise 12.1

import pygame
import sys

class CaracterGame:
    
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((1200, 800))
        self.clock = pygame.time.Clock()
        self.bg_color = (50, 66, 168)
        self.rect = self.screen.get_rect()
        self.char = Char(self)
        pygame.display.set_caption("Caracter Game 12.1")
    
   
    def run_game(self):
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    sys.exit()
            self.screen.fill(self.bg_color)
            self.char.blitme()
            pygame.display.flip()
            self.clock.tick(60)

# Exercise 12.2    
class Char:

    def __init__(self, cg):
        self.screen = cg.screen
        self.screen_rect = cg.screen.get_rect()

        self.image = pygame.image.load("./images/babel.png")
        self.rect = self.image.get_rect()
        
        self.rect.center = self.screen_rect.center
    def blitme(self):
        self.screen.blit(self.image, self.rect)
        

if __name__ == '__main__':
    cg = CaracterGame()
    cg.run_game()