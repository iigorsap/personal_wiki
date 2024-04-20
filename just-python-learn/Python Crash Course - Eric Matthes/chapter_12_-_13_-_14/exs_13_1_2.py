import pygame
from random import randint

class StarPrint:

    def __init__(self):
        pygame.init()
        pygame.display.set_caption("stars")
        self.screen = pygame.display.set_mode(size=(1200, 800))
        self.stars = pygame.sprite.Group()
        self.clock = pygame.time.Clock()

    def run_game(self):
        while True:
            self._update_screen()
            self._create_stars()
            self.clock.tick(60) # O método tick() recebe um argumento: a taxa de quadros do jogo.

    def _update_screen(self):
        self.stars.draw(self.screen)
        # Tornar visível a tela desenhada mais recentemente.
        pygame.display.flip()

    def _create_stars(self):
        """Exercise 13.2"""   
        star = Star(self)
        star_width, star_heigth = star.rect.size
             
        while len(self.stars) < 30: 
            current_x, current_y = randint(0, 1200), randint(0, 800) 
            self._create_star(current_x, current_y)
            current_x = randint(0, 1200)
            current_y += 1.5 * randint(0, 800)

    def _create_star(self, x_position, y_position):
            new_star = Star(self) 
            new_star.x = x_position 
            new_star.rect.x = x_position 
            new_star.rect.y = y_position
            self.stars.add(new_star) 

class Star(pygame.sprite.Sprite):
    
    def __init__(self, ai_game):
        super().__init__()
        self.screen = ai_game.screen 

        # Load the star image and set its rect attribute.
        self.image = pygame.image.load("images\\mario-star.png")
        self.image = pygame.transform.scale(self.image, (36, 36))

        self.rect = self.image.get_rect()
     
        # Start each new star near the top left of the screen.
        self.rect.x = self.rect.width
        self.rect.y = self.rect.height

        # Store the star's exact horizontal position.
        self.x = float(self.rect.x)

if __name__ == '__main__':
    # Crie uma instância de jogo e execute o jogo.
    star = StarPrint()
    star.run_game()