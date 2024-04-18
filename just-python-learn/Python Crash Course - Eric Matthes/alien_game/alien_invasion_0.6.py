import sys # Uso de algumas ferramentas do sys para sair do game quando o jogador sair
import pygame 

from settings import Settings
from ship import Ship
from bullet import Bullet
from alien import Alien

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
        
        """FULLSCREEN mode"""
        # self.screen = pygame.display.set_mode(
        #     (0, 0), pygame.FULLSCREEN)
        # self.settings.screen_width = self.screen.get_rect().width
        # self.settings.screen_heigth = self.screen.get_rect().height
 
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
        # pygame.sprite.Group, que se comporta como uma lista com algumas
        # funcionalidade extra que é útil ao criar jogos.
        self.bullets = pygame.sprite.Group()
        self.aliens = pygame.sprite.Group()
        
        self._create_fleet()

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
            self._update_bullets()
            self._create_fleet()
            self._update_aliens()
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
        elif event.key == pygame.K_SPACE:
            self._fire_bullet()
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
        # bullets.sprites este método retorna a lista de todos os sprites no grupo bullets,
        # lembrando que bullets herda de Sprites,  o que faz com que todos os bullets se comportam como grupo
        for bullet in self.bullets.sprites():
            bullet.draw_bullet()
        self.ship.blitme()
        self.aliens.draw(self.screen)

        # Tornar visível a tela desenhada mais recentemente.
        pygame.display.flip()
    
    def _fire_bullet(self):
        """Criando um novo tiro e adicionando ele ao grupo de tiros da nave"""
        if len(self.bullets) < self.settings.bullets_allowed:
            new_bullet = Bullet(self)
            # add() é similar a append(), porém foi uma método especificamente para lidar 
            # com pygame.groups
            self.bullets.add(new_bullet)

    def _update_bullets(self):
        # Atualizar posições do bullet
        self.bullets.update()
        
        # Eliminar os bullets que desapareceram como não é possivel remover os elementos de uma lista
        # ou grupo enquanto itera sobre eles, usamos uma copia do groupo de bullets assim conseguimos
        # referenciar o bullet no grupo principal e removê-lo, caso ele tiver passado do topo da tela.
        for bullet in self.bullets.copy():
            if bullet.rect.bottom <= 0:
                self.bullets.remove(bullet)

    def _update_aliens(self):
        """Verifique se a frota está em uma borda e, em seguida, atualize as posições."""
        self._check_fleet_edges()
        self.aliens.update()

    def _create_fleet(self):
        """Create the fleet of aliens"""
        # Make an alien
        alien = Alien(self) # Este self é o ai_game
        # Crie um alienígena e continue adicionando alienígenas até que não haja mais espaço.
        # O espaço entre os alienígenas é de uma largura e altura de um alien.
        alien_width, alien_heigth = alien.rect.size

        current_x, current_y = alien_width, alien_heigth # Referencia de posicao para o proximo alien
        while current_y < (self.settings.screen_heigth - 3 * alien_heigth):
            while current_x < (self.settings.screen_width - 1.5 * alien_width):
                self._create_alien(current_x, current_y)
                current_x += 1.5 * alien_width
    
            # Finalizando uma linha reseta o valor do x e acrescenta o valor do y
            current_x = alien_width
            current_y += 1.5 * alien_heigth
    
    def _check_fleet_edges(self):
        """Diz se a frota alcançou a aresta"""
        for alien in self.aliens.sprites():
            if alien.check_edges():
                self._change_fleet_direction()
                break
    
    def _change_fleet_direction(self):
        """Derrube toda a frota e mude a direção da frota."""
        for alien in self.aliens.sprites():
            alien.rect.y += self.settings.fleet_drop_speed
        self.settings.fleet_direction *= -1
    
    def _create_alien(self, x_position, y_position):
            """Crie um alienígena e coloque-o na fileira."""
            new_alien = Alien(self) # Cria novo alien
            new_alien.x = x_position # adiciona a posicao real do alien na posicao de referencia
            new_alien.rect.x = x_position # adiciona o rectangulo do alien na posicao de referencia
            new_alien.rect.y = y_position
            self.aliens.add(new_alien) 

if __name__ == '__main__':
    # Crie uma instância de jogo e execute o jogo.
    ai = AlienInvasion()
    ai.run_game()