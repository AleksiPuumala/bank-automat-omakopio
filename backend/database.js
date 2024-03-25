const mysql=require('mysql2');
//const dotenv=require('dotenv');
//dotenv.config();

const conn="mysql://user:pass@localhost:3306/bank_automat";

const connection=mysql.createPool(conn);

//const connection=mysql.createPool(process.env.MySQL_DB);

module.exports=connection;