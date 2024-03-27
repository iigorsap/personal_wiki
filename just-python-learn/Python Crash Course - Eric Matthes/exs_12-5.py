# Exercise 12.5

import pygame
import sys

class KDTest:
    
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((1200, 800))
        self.clock = pygame.time.Clock()
        self.bg_color = (50, 66, 168)
        pygame.display.set_caption("test 12.5")
   
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

    def _check_events(self):
        # Observe os eventos do teclado e do mouse.            
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
               print(event.key)
    

if __name__ == '__main__':
    cg = KDTest()
    cg.run_game()

"""
R:
103
119
101
103
119
101
103
115
100
103
115
100
103
1073742051
102
97
119
102
119
102
97
102
115
102
100
9
119
101
101
114
114
116
116
121
117
105
92
122
99
120
99
120
118
99
98
"""