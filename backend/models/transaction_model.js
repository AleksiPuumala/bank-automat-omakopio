const db=require('../database');

const transaction={
    getAllTransaction(callback){
        return db.query("SELECT * FROM transaction",callback);
    },
    addTransaction(newTransaction, callback){
        return db.query("INSERT INTO transaction VALUES(?,?,?,?,?,?)",[newTransaction.idaccount,newTransaction.time,newTransaction.transactionamount, newTransaction.transactiontype,newTransaction.idtransaction,newTransaction.cardnumber],callback);
    },
    updateTransaction(updatedTransaction, callback){
        return db.query("UPDATE transaction SET time=?, transactionamount=?, transactiontype=?, cardnumber=? WHERE idtransaction=?", [time, transactionamount, transactiontype, cardnumber, idaccount, idtransaction], callback);
    },
    getOneTransaction(idtransaction, callback) {
        return db.query("SELECT * FROM transaction WHERE idtransaction=?", [idtransaction], callback);
    },
    deleteTransaction(idtransaction, callback) {
        return db.query("DELETE FROM transaction WHERE idtransaction=?", [idtransaction], callback);
    }
}

module.exports = transaction;