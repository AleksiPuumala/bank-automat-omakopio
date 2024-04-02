const db=require('../database');

const user={
    getAllUser(callback){
        return db.query('SELECT * FROM user',callback);
    },
    getOneUser(id, callback){
        return db.query('SELECT * FROM user WHERE idcustomer=?',[id],callback);
    },
    addUser(callback){

    },
    updateUser(callback){

    },
    deleteUser(callback){
        return db.query('DELETE FROM customer WHERE idcustomer=?',[id],callback)
    }
}