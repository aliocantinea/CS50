import csv
import sys


def main():

    # TODO: Check for command-line usage
    # sys.argv is equal to 3 because it includes program and two commnad line arguments (data and sequence)
    if len(sys.argv) != 3:
        print('Please follow this usage: python dna.py data.csv sequence.txt')
        sys.exit(1)

    # TODO: Read database file into a variable

    with open(sys.argv[1], 'r') as csvfile:
        # Reads first command line argument into a dict with header
        dict_strs = csv.DictReader(csvfile)
        # first key in dict is name, remove 1 vallue for total matches
        tandrpts = dict.fromkeys(dict_strs.fieldnames)

        # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2]) as txtfile:
            dna = txtfile.read()

        # TODO: Find longest match of each STR in DNA sequence
        # For each STR in list call longest_match function
        totalmatch = 0
        for tandrpt in tandrpts:
            # Keep track of total STR values to compare when finding a match
            totalmatch += 1
            tandrpts[tandrpt] = longest_match(dna, tandrpt)

        # TODO: Check database for matching profiles
        # Compare values for each row in csv file to longest found STRs in tandrpt dict
        for row in dict_strs:
            # Keep track of how many matches there are found
            match = 0
            for item in tandrpts:
                if str(tandrpts[item]) == str(row[item]):
                    # TESTING print(f'{tandrpts[item]}, {row[item]}')
                    match += 1
                # Totalmatch is -1 because firts key is 'name' header taken from csv file
                # If every value matches total number of STRs print name
                if (totalmatch - 1) == match:
                    print(row['name'])
                    sys.exit(3)


    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
