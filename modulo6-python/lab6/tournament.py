# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    # TODO: Ler equipes na memória a partir do arquivo

    with open(sys.argv[1], newline='') as file:
        reader = csv.DictReader(file)

        for row in reader:
            rating = int(row['rating'])
            row['rating'] = rating
            teams.append(row)

    counts = {}

    # TODO: Simulate N tournaments and keep track of win counts
    # TODO: Simule N torneios e acompanhe a contagem de vitórias
    for i in range(0, N):
        winner = simulate_tournament(teams)
        if winner not in counts:
            counts[winner] = 0
        counts[winner] += 1



    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    # Simule uma rodada. Retorne uma lista das equipes vencedoras.
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # Simule um torneio. Retorne o nome da equipe vencedora.
    winner = teams
    while True:

        winner = simulate_round(winner)
        if len(winner) == 1:
            vencedor = winner[0]['team']
            return vencedor

    # TODO


if __name__ == "__main__":
    main()
