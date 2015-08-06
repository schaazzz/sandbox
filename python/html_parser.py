import os, sys
from HTMLParser import HTMLParser

# Parses the page returned from a URL returned by the flickr.photos.getSizes()
# to retrieve the image URL...
class MyHTMLParser(HTMLParser):
    div_found = False

    def handle_starttag(self, tag, attrs):

        if tag == 'div':
            if 'allsizes-photo' in attrs[0][1]:
                self.div_found = True

        if tag == "img" and self.div_found:
            url = attrs[0][1]
            print url
            self.div_found = False

    def handle_endtag(self, tag):
        pass

    def handle_data(self, data):
        pass

parser = MyHTMLParser()
parser.feed(open(os.path.join("",sys.argv[1])).read())
