import sys
input = sys.stdin.readline

def checkLevel(newUser, firstUser):
    return (firstUser - 10) <= newUser <= (firstUser + 10)

def enterUser(gameQueue, user, m):
    isAdd = False
    level, id = user

    for game in gameQueue:
        if len(game) == m:
            continue
        if checkLevel(level, game[0][0]):
            game.append([level, id])
            isAdd = True
            break

    if not isAdd:
        gameQueue.append([[level, id]])

def printAnswer(gameQueue):
    for game in gameQueue:
        game.sort(key = lambda k: k[1])

        print("Started!" if len(game) == m else "Waiting!")
        for user in game:
            print(*user)

p, m = map(int, input().split())
gameQueue = []

for _ in range(p):
    user = list(map(str, input().strip().split()))
    user[0] = int(user[0])

    enterUser(gameQueue, user, m)
printAnswer(gameQueue)
