import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) is False:
        print("Usage Error: ./python ./data.py ./CSVfile ./sequence.txt")
        exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as csvfile:  # Using 'with' automatically closes file - no need for csvfile.close()
        csv_reader = csv.DictReader(csvfile)
        header = csv_reader.fieldnames[1:]  # .fieldnames collects top elements of csvfile

    # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2]) as dnafile:
            dna_reader = dnafile.read()
            actual = [longest_match(dna_reader, STR) for STR in header]
            # longest_match() reads over txt and collects longest int per individual STR
            # actual takes the longest_match int(STR) from .txt file,
            # and makes a [list of those values] correlating to header[STR values]

            for person in csv_reader:
                name = list(person.values())[0]    # name = person['name'] also works
                values = list(person.values())[1:]  # define values as the list from [1:] - but are strings
                for i in range(0, len(values)):    # Since ['values'] != [values] we convert the string ints of ['values']...
                    values[i] = int(values[i])  # ...from ['values'] to [values]
                    if values == actual:           # And then we can [values] = [values]
                        print(name)
                        return
            print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

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