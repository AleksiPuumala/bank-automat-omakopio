const db=require('../database');

const user={
    getAllUser(callback){
        return db.query('SELECT * FROM user',callback);
    },
    getOneUser(id, callback){
        return db.query('SELECT * FROM user WHERE idaccount=?',id,callback);
    },
    addUser(newUser, callback){
        return db.query('INSERT INTO user (idaccount, idcustomer) VALUES (?,?)',[newUser.idaccount,newUser.idcustomer],callback);
    },
    updateUser(id,updateData, callback){
        return db.query('UPDATE user SET idcustomer=? WHERE idaccount=?',[updateData.idcustomer,id],callback);
    },
    deleteUser(id,callback){
        return db.query('DELETE FROM user WHERE idcustomer=?',id,callback);
    }
}
module.exports=user;