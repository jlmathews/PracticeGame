# PracticeGame

## Checkout

`git clone https://github.com/jlmathews/PracticeGame.git`

`git submodule update --init --recursive`

## Setup

### Redis

Follow Redis install instructions here https://redis.io/topics/quickstart.

Start Redis server:
Linux command: `sudo service redis-server start`
To verify Redis server is running, run the command `redis-cli` which should open the Redis CLI.

To setup access to redis through c++, follow installation instructions for redis-plus-plus and hiredis https://github.com/sewenew/redis-plus-plus#installation.

### LUA

Install LUA 5.3.

### Doxygen

To generate Doxygen documentation, install:
`sudo apt-get install doxygen graphviz`

### Plantuml

To generate plantuml diagrams under ./docs/design/uml, install:
`sudo apt-get install plantuml`

### Third-Party Repos

List of third-party repos included:
* https://github.com/sewenew/redis-plus-plus
* https://github.com/redis/hiredis
* https://github.com/ThePhD/sol2
* https://github.com/ToruNiina/toml11
* https://github.com/a-n-t-h-o-n-y/TermOx

## Build

### Build all tests and projects

`./build.sh`

### Generate Documentation

`./generate_docs.sh`
