import random


def play():
    welcome_message()
    secret_word = load_secret_word()

    letter_board = init_letter_board(secret_word)
    print(letter_board)

    hanged = False
    hit = False
    mistakes = 0

    while (not hanged and not hit):

        guess = get_guess()

        if (guess in secret_word):
            mark_correct_guess(guess, letter_board, secret_word)
        else:
            mistakes += 1
            draw_hangman(mistakes)

        hanged = mistakes == 6
        hit = "_" not in letter_board
        print(letter_board)

        if (hit):
            print_winner_message()
        elif (hanged):
            print_loser_message(secret_word)

    print("End Game")


def welcome_message():
    print("*****************************")
    print("***Welcome to the Hangman!***")
    print("*****************************")


def load_secret_word():
    words = []
    with open("words.txt", "r") as archive:
        for line in archive:
            line = line.strip()
            words.append(line)

    number = random.randrange(0, len(words))
    secret_word = words[number].upper()
    return secret_word


def init_letter_board(secret_word):
    return ["_" for letter in secret_word]


def get_guess():
    guess = input("Which letter?")
    guess = guess.strip().upper()
    return guess


def mark_correct_guess(guess, letter_board, secret_word):
    index = 0
    for letter in secret_word:
        if (guess == letter):
            letter_board[index] = letter
        index += 1


def print_winner_message():
    print("Congratulations, you win!")
    print("       ___________      ")
    print("      '._==_==_=_.'     ")
    print("      .-\\:      /-.    ")
    print("     | (|:.     |) |    ")
    print("      '-|:.     |-'     ")
    print("        \\::.    /      ")
    print("         '::. .'        ")
    print("           ) (          ")
    print("         _.' '._        ")
    print("        '-------'       ")


def print_loser_message(secret_word):
    print("My bad, you were hanged!")
    print("The word was {}".format(secret_word))
    print("    _______________         ")
    print("   /               \       ")
    print("  /                 \      ")
    print("//                   \/\  ")
    print("\|   XXXX     XXXX   | /   ")
    print(" |   XXXX     XXXX   |/     ")
    print(" |   XXX       XXX   |      ")
    print(" |                   |      ")
    print(" \__      XXX      __/     ")
    print("   |\     XXX     /|       ")
    print("   | |           | |        ")
    print("   | I I I I I I I |        ")
    print("   |  I I I I I I  |        ")
    print("   \_             _/       ")
    print("     \_         _/         ")
    print("       \_______/           ")


def draw_hangman(mistakes):
    print("  _______     ")
    print(" |/      |    ")

    if (mistakes == 1):
        print(" |      (_)   ")
        print(" |            ")
        print(" |            ")
        print(" |            ")

    if (mistakes == 2):
        print(" |      (_)   ")
        print(" |      \     ")
        print(" |            ")
        print(" |            ")

    if (mistakes == 3):
        print(" |      (_)   ")
        print(" |      \|    ")
        print(" |            ")
        print(" |            ")

    if (mistakes == 4):
        print(" |      (_)   ")
        print(" |      \|/   ")
        print(" |            ")
        print(" |            ")

    if (mistakes == 5):
        print(" |      (_)   ")
        print(" |      \|/   ")
        print(" |       |    ")
        print(" |            ")

    if (mistakes == 6):
        print(" |      (_)   ")
        print(" |      \|/   ")
        print(" |       |    ")
        print(" |      /     ")

    if (mistakes == 7):
        print(" |      (_)   ")
        print(" |      \|/   ")
        print(" |       |    ")
        print(" |      / \   ")

    print(" |            ")
    print("_|___         ")
    print()


if (__name__ == "__main__"):
    play()
