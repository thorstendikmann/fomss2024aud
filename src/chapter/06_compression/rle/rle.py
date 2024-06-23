import logging
logger = logging.getLogger("rle")


def rle_decompress(compressed_data: str) -> str:
    """Decompress string with run length encoding

    Args:
        compressed_data (str): the compressed string coming from rle_compress(),
        e.g. <em>k5w5a4s2d2u1g6w1p5</em>.

    Returns:
        str: The "original" decompressed string, e.g.
        <em>kkkkkwwwwwaaaassdduggggggwppppp</em>.
    """
    decoded_message: str = ""

    i: int = 0
    while i < len(compressed_data)-1:
        j: int = 1
        count: int = 0
        # compressed_data[i] is the char and compressed_data[i+1] the count
        # ... but: if the char repeats >9 times, then we need to check compressed_data[i+2] as well.
        # Let's see how many numeric chars we have.
        while (i+j < len(compressed_data) and compressed_data[i+j].isnumeric()):
            # when we already found a numeric char before, we know: each additional char is another decimal place
            if j > 1:
                count *= 10
            count += int(compressed_data[i+j])
            j += 1

        # We now know how many characters have to be repeated
        decoded_message += compressed_data[i] * count
        i += j

    return decoded_message


def rle_compress(uncompressed_data: str) -> str:
    """Compress string with run length encoding

    Args:
        uncompressed_data (str): A string consisting from ![0-9] (non-numeric) 
        characters, e.g. <em>kkkkkwwwwwaaaassdduggggggwppppp</em>.

    Returns:
        str: the compressed string, e.g. <em>k5w5a4s2d2u1g6w1p5</em>
    """
    encoded_message: str = ""

    i: int = 0
    # iterate through the uncompressed string
    while i < len(uncompressed_data)-1:
        # counting repetive chars
        count: int = 1
        # as long as we see the same char ...
        while (i < (len(uncompressed_data)-1) and uncompressed_data[i] == uncompressed_data[i+1]):
            # ... keep counting
            i = i+1
            count = count + 1

        # go to next char
        i = i+1

        encoded_message += uncompressed_data[i - 1] + str(count)

    return encoded_message


if __name__ == "__main__":
    string = "kkkkkwwwwwaaaassdduggggggwppppp"
    compressed_str = rle_compress(string)
    decompressed_str = rle_decompress(compressed_str)

    print(f"Original string    : {string}")
    print(f"Compressed string  : {compressed_str}")
    print(f"Decompressed string: {decompressed_str}")

    string = "zzwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwbbbbbbbddddddffqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqrrrttttttttttttttttttttttttt"
    compressed_str = rle_compress(string)
    decompressed_str = rle_decompress(compressed_str)

    print(f"Original string    : {string}")
    print(f"Compressed string  : {compressed_str}")
    print(f"Decompressed string: {decompressed_str}")
