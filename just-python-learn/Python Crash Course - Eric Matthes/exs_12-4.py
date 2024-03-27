# Exercise 12.4

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
        pygame.display.set_caption("Caracter Game 12.4")
   
    def run_game(self):
        """Inicie o loop principal do jogo."""
        """
        Quando ativar o loop de animação do jogo, 
        essa superfície será redesenhada a cada passagem pelo loop, 
        para que possa ser atualizada com quaisquer alterações 
        acionadas pela entrada do usuário.
        """
        while True:
            self._check_events()
            self.char.update()
            self._update_screen()
            self.clock.tick(60) # O método tick() recebe um argumento: a taxa de quadros do jogo.

    def _check_events(self):
        # Observe os eventos do teclado e do mouse.            
        for event in pygame.event.get():
            """ pygame.event.get() : Essa função retorna uma lista de eventos 
            que ocorreram desde a última vez que essa função foi chamada.
            Por exemplo, quando o jogador clica no botão Fechar da janela do jogo, 
            um evento pygame.QUIT é detectado e chamamos sys.exit() para sair do jogo 5.
            """                
            
            """
            Um evento é uma ação que o usuário faz enquanto 
            joga o jogo, como pressionar uma tecla ou mover o mouse.
            """

            """
            keyup(): o evento ocorre quando a tecla retorna à posição original no 
            teclado (i.e. quando você solta a mesma).

            keydown(): o evento ocorre quando a tecla é pressionada. O evento 
            repete enquanto a tecla estiver 
            pressionada (exceto para as teclas Ctrl, Alt e Shift).

            keypress(): o evento ocorre quando a tecla está pressionada. 
            O evento repete enquanto a tecla estiver pressionada 
            (exceto para as teclas Ctrl, Alt e Shift).
            """
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
               self._check_keydown_events(event)
            elif event.type == pygame.KEYUP:
               self._check_keyup_events(event)

    def _check_keydown_events(self, event):
        """Respond to keypresses."""
        if event.key == pygame.K_RIGHT:
            # move a nave para direita
            self.char.moving_right = True
        elif event.key == pygame.K_LEFT:
            # move a nave para esquerda
            self.char.moving_left = True
        elif event.key == pygame.K_DOWN:
            # move a nave para baixo
            self.char.moving_down = True
        elif event.key == pygame.K_UP:
            # move a nave para cima
            self.char.moving_up = True
        elif event.key == pygame.K_q:
            sys.exit()

    def _check_keyup_events(self, event):
        """Respond to key releases."""
        if event.key == pygame.K_RIGHT:
            self.char.moving_right = False
        elif event.key == pygame.K_LEFT:
            self.char.moving_left = False
        elif event.key == pygame.K_DOWN:
            self.char.moving_down = False
        elif event.key == pygame.K_UP:
            self.char.moving_up = False

    def _update_screen(self):
        # Redesenhar a tela durante cada passo através do loop
        self.screen.fill(self.bg_color)
        self.char.blitme()
        # Tornar visível a tela desenhada mais recentemente.
        pygame.display.flip()

class Char:

    def __init__(self, cg):
        self.screen = cg.screen
        self.screen_rect = cg.screen.get_rect()

        self.image = pygame.image.load("./images/babel.png")
        self.rect = self.image.get_rect()
        
        self.rect.center = self.screen_rect.center
        self.x = float(self.rect.x)
        self.y = float(self.rect.y)
        self.char_speed = 5.5

        self.moving_left  = False
        self.moving_right = False
        self.moving_down  = False
        self.moving_up    = False

    def update(self):
        """update the ship's position based on the movement flag."""
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.x += self.char_speed
        
        if self.moving_left and self.rect.left > 0:
            self.x -= self.char_speed
        
        if self.moving_down and self.rect.bottom < self.screen_rect.bottom:
            self.y += self.char_speed
        
        if self.moving_up and self.rect.top > 0:
            self.y -= self.char_speed

        self.rect.x = self.x
        self.rect.y = self.y
    
    def blitme(self):
        self.screen.blit(self.image, self.rect)
    

if __name__ == '__main__':
    cg = CaracterGame()
    cg.run_game()