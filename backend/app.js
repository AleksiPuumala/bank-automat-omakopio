var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt=require('jsonwebtoken');

var indexRouter = require('./routes/index');

var transactionRouter = require('./routes/transaction');
var customerRouter = require('./routes/customer');
var userRouter = require('./routes/user');
var cardRouter = require('./routes/card');
var accountRouter = require('./routes/account');
var cardtypeRouter = require('./routes/cardtype');

var loginRouter = require('./routes/login');


var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);

app.use('/login', loginRouter);
app.use(authenticateToken);
app.use('/transaction', transactionRouter);
app.use('/customer', customerRouter);
app.use('/user', userRouter);
app.use('/cardtype', cardtypeRouter);
app.use('/card', cardRouter);
app.use('/account', accountRouter);

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, function(err, user) {
  
      if (err) return res.sendStatus(403)

      req.user = user
  
      next()
    })
  }

module.exports = app;
