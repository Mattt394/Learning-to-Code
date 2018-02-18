import nltk
from nltk.tokenize import TweetTokenizer

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        # TODO
        posi_f = open(positives, 'r')
        nega_f = open(negatives, 'r')

        self.positives = {}
        self.negatives = {}

        # This says word but it actually takes the line, however each word is
        # on a new line so it works and gets rid of the commented lines
        for word in posi_f.read().split():
            w = word.strip()
            if not w.startswith(';'):
                self.positives[w] = 0


        for word1 in nega_f.read().split():
            w1 = word1.strip()
            if not w1.startswith(';'):
                self.negatives[w1] = 0

        posi_f.close()
        nega_f.close()



    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        # TODO

        tkzr = TweetTokenizer()
        tokens = tkzr.tokenize(text)
        positive = dict(self.positives)
        negative = dict(self.negatives)

        #just in case
        neutral_words = 0
        for token in tokens:
            if token in positive:
                positive[token] += 1
            elif token in negative:
                negative[token] += 1
            else:
                neutral_words += 1

        p = sum(positive.values())
        n = sum(negative.values())
        score = p-n

        return score
