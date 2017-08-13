
#Copyright Jonathan Moore 2017

# List all available installed packages on your machine.
installed.packages()

# List all "attached" or loaded packages.
search()

# install rplos package
install.packages("rplos")
#load the rplos library
library('rplos')
search()

install.packages("fulltext")
library('fulltext')
search()

searchplos('genetics', 'id,journal,title,publication_date', limit = 40)

