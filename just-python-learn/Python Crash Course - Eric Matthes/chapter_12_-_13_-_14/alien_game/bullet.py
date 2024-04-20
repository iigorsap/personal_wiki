import pygame
from pygame.sprite import Sprite

class Bullet(Sprite):
    """Classe que genrencia os bullets atirados pela nave"""

    """
    A classe Bullet herda de Sprite, que importamos do módulo pygame.sprite. 
    Ao usar sprites, você pode agrupar elementos relacionados em seu jogo e 
    agir em todos os elementos agrupados de uma só vez. Para criar uma instância de bala, 
    __init__() precisa da instância atual de AlienInvasion, e chamamos super() para herdar 
    adequadamente do Sprite. Também definimos atributos para os objetos de tela e configurações 
    e para a cor da bala. Em seguida, criamos o atributo do retângulo da bala. 
    A bala não é baseada em uma imagem, portanto, temos de criar um retângulo do zero usando 
    a classe pygame.Rect(). Essa classe requer as coordenadas x e y do canto superior esquerdo
    do retângulo, bem como a largura e a altura do retângulo. Inicializamos o retângulo em (0, 0), 
    mas o moveremos para o local correto na próxima linha, pois a posição da bala depende 
    da posição da nave. Obtemos a largura e a altura do projétil a partir dos valores 
    armazenados em self.settings. Definimos o atributo midtop da bala para 
    corresponder ao atributo midtop da nave. Isso fará com que a bala saia do topo da nave, 
    fazendo com que pareça que a bala foi disparada da nave. Usamos um float para a coordenada y 
    da bala para que possamos fazer ajustes finos na velocidade da bala. 
    """    
    def __init__(self, ai_game):
        super().__init__()
        self.screen = ai_game.screen
        self.settings = ai_game.settings
        self.color = self.settings.bullet_color

        # create a bullet rect at (0, 0) and then set correct position.
        self.rect = pygame.Rect(0, 0, self.settings.bullet_width, self.settings.bullet_heigth)
        self.rect.midtop = ai_game.ship.rect.midtop

        # Store the bullet's posisition as a float
        self.y = float(self.rect.y)
        self.moving_up = False

    # Aqui está a segunda parte do bullet.py, update() e draw_bullet()
    def update(self):
        """Move the bullet up the screen"""
        # Update the exact position of the bullet.
        self.y -= self.settings.bullet_speed
        # Update rect position.
        self.rect.y = self.y

    def draw_bullet(self):
        """Draw the bullet to the screen"""
        """
        A função draw.rect() preenche a parte da tela definida pelo  bullet's rect
        com a cor armazenada em self.color
        """
        pygame.draw.rect(self.screen, self.color, self.rect)
    