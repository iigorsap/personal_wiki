import sys # Uso de algumas ferramentas do sys para sair do game quando o jogador sair
import pygame 

from settings import Settings
from ship import Ship

class AlienInvasion:
    """Classe geral para gerenciar ativos e comportamento do jogo."""
    def __init__(self):
        """Inicialize o jogo e crie recursos de jogo."""
        # Inicializa o background de configurações para o pygame funcionar
        pygame.init() 
        self.settings = Settings()

        # Escolhendo o tamanho da tela e salvando a tela no attr screen da classe
        # screen é chamado da superficie
        # A superficie no pygame que é onde os elementos do game podem ser mostrados
        # Cada elemento do jogo como uma nave ou um E.T tem sua propria interface
        self.screen = pygame.display.set_mode(
            (self.settings.screen_width, self.settings.screen_heigth))
 
        """
         Criaremos um relógio e garantiremos que o relógio faça tique-taque 
         uma vez em cada passagem pelo loop principal. 
         Sempre que o loop processar mais rápido do que a taxa que definimos,
         o Pygame calculará o tempo correto de pausa para que o jogo seja 
         executado em uma taxa consistente.
        """
        self.clock = pygame.time.Clock()


        pygame.display.set_caption("Alien Invasion")
        self.ship = Ship(self)

        # Definir a cor do plano de fundo.
        self.bg_color = (self.settings.bg_color)

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
            self.ship.update()
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
            self.ship.moving_right = True
        elif event.key == pygame.K_LEFT:
            # move a nave para esquerda
            self.ship.moving_left = True
        elif event.key == pygame.K_q:
            sys.exit()

    def _check_keyup_events(self, event):
        """Respond to key releases."""
        if event.key == pygame.K_RIGHT:
            self.ship.moving_right = False
        elif event.key == pygame.K_LEFT:
            self.ship.moving_left = False

    def _update_screen(self):
        # Redesenhar a tela durante cada passo através do loop
        self.screen.fill(self.bg_color)
        self.ship.blitme()
        # Tornar visível a tela desenhada mais recentemente.
        pygame.display.flip()
 


if __name__ == '__main__':
    # Crie uma instância de jogo e execute o jogo.
    ai = AlienInvasion()
    ai.run_game()