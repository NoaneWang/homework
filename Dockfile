FROM frolvlad/alpine-gxx
WORKDIR /app/
COPY lexer.cpp ./
RUN g++ lexer.cpp -o lexer
RUN chmod +x lexer