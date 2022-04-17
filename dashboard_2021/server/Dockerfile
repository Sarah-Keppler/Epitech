FROM node

WORKDIR /app

COPY package.json ./

RUN npm i -g @adonisjs/cli && npm install

COPY . .

EXPOSE 8080

ENV PORT 8080

CMD ["npm", "start"]
