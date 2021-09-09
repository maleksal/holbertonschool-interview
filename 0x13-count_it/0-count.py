#!/usr/bin/python3
""" Reddit hot article word count """
import requests


def count_words(subreddit, word_list, after='', words_counting={}):
    """ Word counting function """

    url, headers, payload = (

        "https://www.reddit.com/r/{}/hot.json".format(subreddit),

        {'User-Agent': 'custom'},

        {'limit': '100', 'after': after}
    )
    response = requests.get(

        url, headers=headers,
        params=payload, allow_redirects=False
    )

    if not response.status_code == 200:
        return

    data = response.json().get('data')
    after, children_list = (
        data.get('after'),
        data.get('children')
    )

    titles = [
        c.get('data').get('title') for c in children_list
    ]

    for title in titles:

        for word in word_list:

            ocurrences = title.lower().split().count(word.lower())

            if ocurrences > 0:

                words_counting[word] = sum(
                    [words_counting[word], ocurrences])\
                    if word in words_counting else ocurrences

    if after is not None:

        return count_words(subreddit, word_list, after, words_counting)

    else:

        if not len(words_counting) > 0:
            return

        iterator = sorted(words_counting.items(),
                          key=lambda kv: (-kv[1], kv[0]))

        [
            print('{}: {}'.format(key.lower(), value))
            for key, value in iterator
        ]
