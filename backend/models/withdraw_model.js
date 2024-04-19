const db=require('../database');

const withdraw={
    withdraw(newWithDraw, callback){
        return db.query("CALL withDrawBalance(?,?,?)",[newWithDraw.idaccount, newWithDraw.transactionamount, newWithDraw.cardnumber], callback);
        }
}

module.exports = withdraw;