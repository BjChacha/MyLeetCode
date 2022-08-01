from Tools.ProblemScraper.main import main as ProblemScraper
from Tools.Integrate.main import main as Integrate


def main():
    flag = input("Toolbox: \n\t(1) Problem Scraper\n\t(2) Integrate\n\t(q) Quit\n\nEnter your choice: ")
    if flag == "1":
        ProblemScraper()
    elif flag == "2":
        Integrate()
    elif flag == "q":
        exit()
    else:
        print("Invalid input.")


if __name__ == "__main__":
    main()
