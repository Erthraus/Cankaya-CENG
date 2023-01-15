import random

print("-----------GUESS GAME------------")
print("I'll try to guess your number (Your number should be between 1 and 1000)")

guess = 500
temp = 500
flag = 1
counter1 = 0
counter2 = 0

while flag != 0:
    counter1 += 1
    print("Is your number bigger than", guess)
    answer = input("(Yes, No or Equal): ")
    temp = temp//2
    if temp == 0:
        temp = 1
    if answer == "Yes" or answer == "yes":
        guess += temp
    elif answer == "No" or answer == "no":
        guess -= temp
    elif answer == "Equal" or answer == "equal":
        print("I guessed your number in {0} turns".format(counter1))
        flag = 0
    else:
        print("You have entered a wrong answer")

print("It's your time to guess")
num = random.randint(1, 1000)

while flag == 0:
    userguess = int(input("Guess a number between 1 and 1000: "))
    counter2 += 1
    if userguess > num:
        print("Too high, try again")
    elif userguess < num:
        print("Too low, try again")
    elif userguess == num:
        print("Congratulations, you guessed in {0} turns".format(counter2))
        flag = 1
    else:
        print("You have entered a wrong input!")
        
if counter2 < counter1:
    print("It seems you have won, congratulations.\nYou guessed in {0} turns\nI guessed in {1} turns".format(counter2, counter1))
    
elif counter2 > counter1:
    print("It seems I have won!\nYou guessed in {0} turns\nI guessed in {1} turns".format(counter2, counter1))