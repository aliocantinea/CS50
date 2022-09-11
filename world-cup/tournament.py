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
    with open(sys.argv[1]) as file:
        # Because file has fieldnames, leave DictReader fieldnames default, None
        loader = csv.DictReader(file)
        # You have to interact with the fieldnames not loader or you get a DictReader error
        for team in loader:
            # Convert rating from str to int before loading
            team["rating"] = int(team["rating"])
            # Use the .append() fuction to load into list
            teams.append(team)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        winning_team = simulate_tournament(teams)
        # If already won, add to score
        if winning_team in counts:
            counts[winning_team] += 1
        # If first time winning, add to counts with score of 1
        else:
            counts[winning_team] = 1

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
    # TODO
    # Keep simulating until you have only 1 team left
    while len(teams) > 1:
        teams = simulate_round(teams)
    # A single winner should be returned
    # Return first line in teams with [0]
    # Since teams is a dict, ["team"] to just return the name
    return teams[0]["team"]


if __name__ == "__main__":
    main()
