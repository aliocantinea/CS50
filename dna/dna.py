import csv
import sys


def main():

    # TODO: Check for command-line usage
    # sys.argv is equal to 3 because it includes program and two commnad line arguments (data and sequence)
    if len(sys.argv) != 3:
        print('Please follow this usage: python dna.py data.csv sequence.txt')
        sys.exit(1)

    # TODO: Read database file into a variable

    with open(sys.argv[1]) as csvfile:
        # Reads first command line argument into a dict with header
        csvreader = csv.DictReader(csvfile)
        for row in csvreader
            str_values = 
        # Takes header and puts it into a list to compare
        # https://www.geeksforgeeks.org/get-column-names-from-csv-using-python/
    list_of_strs = str_values[0]
    print(f'list_of_strs')
        # Remove first value from header list, since it is the header for key 'name'
    del list_of_strs[0]

    # TODO: Read DNA sequence file into a variable
    sequence = open('sys.argv[2]', 'r')

    # TODO: Find longest match of each STR in DNA sequence
    result = []
    # for each STR in list call longest_match function
    for subsequence in list_of_strs:
        match = longest_match(sequence, subsequence)
        # add longest_match result to result list
        result.append(match)

    # TODO: Check database for matching profiles
    # regex?? str_values with result list to find match,
    # then print key to dict line that matches??

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
