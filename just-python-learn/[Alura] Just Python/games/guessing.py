import random


def play():
    print("*****************************")
    print("Welcome to the Guessing game!")
    print("*****************************")

    secret_number = round(random.randrange(1, 101))  # 0.0 1.0
    total_attempts = 3
    score = 100

    print("Difficulty?")
    print("(1) Easy (2) Medium (3) Hard")

    difficulty = int(input("-> "))
    if (difficulty == 1):
        total_attempts = 20
    elif (difficulty == 2):
        total_attempts = 101
    else:
        total_attempts = 5

    for match_rounds in range(1, total_attempts + 1):
        print("Attempt {} of {}".format(match_rounds, total_attempts))

        typed_number_str = input("Type a number between 1 and 100: ")
        typed_number = int(typed_number_str)
        print("You typed in the number {}".format(typed_number))

        if (typed_number < 1 or typed_number > 100):
            print("You must enter a number between 1 and 100!")
            continue

        correct = typed_number == secret_number
        greater = typed_number > secret_number
        less = typed_number < secret_number

        if (correct):
            print("You got it right, your score was {} points!".format(score))
            break
        elif (greater):
            print("The typed number is higher than the secret number")
            if (match_rounds == total_attempts):
                print("The secret number was {}, your score was {} points".format(secret_number, score))
        else:
            print("The typed number is less than the secret number")
            if (match_rounds == total_attempts):
                print("The secret number was {}, your score was {} points".format(secret_number, score))
        lost_score = abs(secret_number - typed_number)
        score = score - lost_score

    print("Game Over")


if(__name__ == "__main__"):
    play()
