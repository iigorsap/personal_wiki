import guessing
import hangman


def choose_game():
    print("***************************")
    print("Choose your favourite game!")
    print("***************************")

    print("(1) Guessing game (2) Hangman game")

    game = int(input("What's the game?"))

    if(game == 1):
        print("Playing Hangman")
        hangman.play()
    elif(game == 2):
        print("Playing Guessing")
        guessing.play()


if(__name__ == "__main__"):
    choose_game()

