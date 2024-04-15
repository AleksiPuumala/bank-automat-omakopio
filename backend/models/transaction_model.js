const db=require('../database');

const transaction={
    getAllTransaction(callback){
        return db.query("SELECT * FROM transaction",callback);
    },
    addTransaction(newTransaction, callback){
        return db.query("INSERT INTO transaction (idaccount, time, transactionamount, transactiontype, cardnumber) VALUES(?,?,?,?,?)",[newTransaction.idaccount,newTransaction.time,newTransaction.transactionamount, newTransaction.transactiontype,newTransaction.cardnumber],callback);
    },
    updateTransaction(idtransaction, updatedTransaction, callback){
        return db.query("UPDATE transaction SET time=?, transactionamount=?, transactiontype=?, cardnumber=? WHERE idtransaction=?", [updatedTransaction.time, updatedTransaction.transactionamount, updatedTransaction.transactiontype, updatedTransaction.cardnumber, idtransaction], callback);
    },
    getOneTransaction(idtransaction, callback) {
        return db.query("SELECT * FROM transaction WHERE idtransaction=?", idtransaction, callback);
    },
    deleteTransaction(idtransaction, callback) {
        return db.query("DELETE FROM transaction WHERE idtransaction=?", idtransaction, callback);
    },
    withdraw: function (idaccount, transactionamount,callback){
        return db.query("CALL withDrawBalance(?,?)",[idaccount, transactionamount], callback);
    }
}

module.exports = transaction;