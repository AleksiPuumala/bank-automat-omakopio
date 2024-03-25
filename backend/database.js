const mysql=require('mysql2');
const dotenv=require('dotenv');
dotenv.config();

const conn="mysql://user@localhost@127.0.0.1:3306/bank_automat";

const connection=mysql.createPool(conn);

//const connection=mysql.createPool(process.env.MySQL_DB);

module.exports=connection;