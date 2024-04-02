const db=require("../database");

const account={
    getAllAccount(callback){
        return db.query("SELECT * FROM account",callback);
    },
    getOneAccount(id,callback){ 
        return db.query("SELECT * FROM account WHERE idaccount=?",id,callback);
    },
     addOneAccount(newaccount,callback){
        return db.query("INSERT INTO account(idaccount,balance,creditlimit) VALUES(?,?,?)",[newaccount.idaccount, newaccount.balance, newaccount.creditlimit],callback)
     },
     updateOneAccount(id,updateaccount,callback){
        return db.query("UPDATE account SET balance=?, creditlimit=? WHERE idaccount=?",[updateaccount.balance,updateaccount.creditlimit,id],callback)
     },
     deleteOneAccount(id,callback){
        return db.query("DELETE FROM account WHERE idaccount=?",id,callback);
     },


    
}
module.exports=account;