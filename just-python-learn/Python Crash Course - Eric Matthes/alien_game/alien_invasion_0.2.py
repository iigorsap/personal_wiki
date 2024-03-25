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
                if event.type == pygame.QUIT:
                    sys.exit()
            
            # Redesenhar a tela durante cada passo através do loop
            self.screen.fill(self.bg_color)
            self.ship.blitme()
            # Tornar visível a tela desenhada mais recentemente.
            pygame.display.flip()
            self.clock.tick(60) # O método tick() recebe um argumento: a taxa de quadros do jogo.


if __name__ == '__main__':
    # Crie uma instância de jogo e execute o jogo.
    ai = AlienInvasion()
    ai.run_game()