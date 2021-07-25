import argparse
import json
import os

if __name__=='__main__':
    parser = argparse.ArgumentParser(description='Reads cards and plays')
    parser.add_argument('-i', '--input', nargs=1,
                        help='Input file')
    parser.add_argument('-o', '--output', nargs=1,
                        help='Output files')

    args = parser.parse_args()
    infile = args.input[0]
    outfile = args.output[0]
    
    with open(infile, 'r') as f:
        cards = list(json.load(f))
        if (len(cards) > 1): 
            card_ = cards[0]
            deck = cards[1]
        else:
            deck = cards[0]

    with open(outfile, 'w') as f:
        f.write("0")


