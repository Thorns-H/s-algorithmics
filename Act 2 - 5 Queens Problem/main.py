from headers.board import Table
import os

def main() -> None:
    game: Table = Table(5)
    game.start()

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        os.system("cls")