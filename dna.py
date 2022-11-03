import csv
import sys


def main():

    if len(sys.argv) != 2:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    database = []
    with open(sys.argv[1], "r", encoding="utf_8") as file:
        reader = csv.DictReader(file)
        for row in reader:
            database += [row]
        str_list = (list(database[0]))
        del str_list[0]

    with open(sys.argv[2], "r", encoding="utf_8") as file:
        dna_sequence = file.read()

    result_dict = {}
    for i, str_name in enumerate(str_list):
        longest = longest_match(dna_sequence, str_name)
        result_dict[str_name] = str(longest)

    for i, item in enumerate(database):
        person = item['name']
        del item['name']
        if item == result_dict:
            print(person)
            return
    sys.exit("No match")


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
