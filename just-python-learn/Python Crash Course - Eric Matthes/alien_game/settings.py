
class Settings:
    def __init__(self):
        # Screen settings
        self.screen_width = 1200
        self.screen_heigth = 800
        self.bg_color = 230, 230, 230
        self.ship_speed = 1.5
        
        # Bullet settings
        self.bullet_speed = 2.0
        self.bullet_width = 3
        self.bullet_heigth = 15
        self.bullet_color = (60, 60, 60)
        self.bullets_allowed = 3

        # Alien settings 
        self.alien_speed = 1.0
        self.fleet_drop_speed = 10
        # fleet_direction de 1 representa direita; -1 representa esquerda.
        self.fleet_direction = 1 
        