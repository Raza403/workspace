import nltk
import re
class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        #loading positive.txt as dict
        self.positives = []
        #opening file for reading as fpos
        with open('positive-words.txt', 'r') as fpos:
            #iterate over every line
                for line in fpos:
                    #if line don,t start with ";" load it
                    if line.startswith(";") != True:
                        self.positives.append(line.strip())
        #loading negative.txt as dict
        self.negatives = []
        #opening file for reading as fneg
        with open('negative-words.txt', 'r') as fneg:
            #iterate over every line
            for line in fneg:
                #if line don,t start with ";" load it
                if (line.startswith(";") != True):
                    self.negatives.append(line.strip())

    def analyze(self, text):
        #defining tokenizer
        tokenizer = nltk.tokenize.TweetTokenizer()
        #tokenizing text/tweet
        tokens = tokenizer.tokenize(text)
        score = 0
        #iterating over all token and checking if they are in positive or negative        
        for token in tokens:
            if token in self.positives:
                score += 1
            elif token in self.negatives:
                score -= 1
            else:
                score = score
            
        return score
