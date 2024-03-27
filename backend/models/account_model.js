const db=require("../database");

const account={
    getAllAccount(callback){
        return db.query("SELECT * FROM account",callback);

    },
    getBalanceAccount(id,callback){
        return db.query("SELECT * FROM balance WHERE idaccount=?",[id],callback);

    },
    getCreditlimit(id,callback){
        return db.query("SELECT * FROM creditlimit WHERE idaccount=?",[id],callback);
    },
    getidaccount(id,callback){
        return db.query("SELECT * FROM idaccount WHERE idaccount=?",[id],callback);
    }
}
module.exports=account;