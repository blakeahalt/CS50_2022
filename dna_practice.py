import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) is False:
        print("Usage Error: ./python ./data.py ./CSVfile ./sequence.txt")
        exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as csvfile:
        csv_reader = csv.DictReader(csvfile)
        header = csv_reader.fieldnames[1:]

    # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2]) as dnafile:
            dna_reader = dnafile.read()
            actual = [longest_match(dna_reader, seq) for seq in header]

            for person in csv_reader:
                name = person['name']
                values = list(person.values())[1:]

                for i in range(0, len(values)):
                    values[i] = int(values[i])
                    if values == actual:
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




import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) is False:
        print("Usage Error: ./python ./data.py ./CSVfile ./sequence.txt")
        exit(1)

    # TODO: Read database file into a variable
    with open(sys.argv[1]) as csvfile:
        csv_reader = csv.DictReader(csvfile)
        header = csv_reader.fieldnames[1:]

    # TODO: Read DNA sequence file into a variable
        with open(sys.argv[2]) as dnafile:
            dna_reader = dnafile.read()
            actual = [longest_match(dna_reader, seq) for seq in header]
        print_match(csv_reader, actual)

def print_match(csv_reader, actual):
    header = csv_reader.fieldnames[1:]
    dnafile = open(sys.argv[2], 'r')
    dna_reader = dnafile.read()
    for person in csv_reader:
# name = list(row.values())[0]
        name = person['name']
        # for STR in header:
        #     int(person[STR][0]) == person[STR][0]
        # print(name)

# values = list(person.values())[1:]
        values = list(person.values())[1:]
        for i in range(0, len(values)):
            values[i] = int(values[i])

        # print(values)
        # print(actual)
        if values == actual:
            print(name)
            return
    print("No match")

def max_times_substring(s, sub):
    ans = [0] * len(s)
    for i in range(len(s) - len(sub), -1, -1):
        if s[i: i + len(sub)] == sub:
            if i + len(sub) > len(s) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]
    return max(ans)

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
