const express=require('express');
const router=express.Router();
const card=require('../models/card_model');
const bcrypt=require('bcryptjs');
const jwt=require('jsonwebtoken');
const dotenv=require('dotenv');
dotenv.config();

router.post('/',function(request,response){
    if(request.body.cardnumber  && request.body.cardpin){
        card.login(request.body.cardnumber, function(err, result){
            if(err){
                console.log('jokin meni pieleen');
                console.log(err.errno);
                response.json(err.errno);
            } else {
                // Tarkistetaan onko syötetty PIN luku tyhjä
                if(result.length > 0){
                    // Tarkistetaan voiko syötetyllä PIN luvulla saada salattua PIN lukua
                    bcrypt.compare(request.body.cardpin, result[0].cardpin, function(err, compareResults){
                        if(compareResults){
                            // Oikealla PIN luvulla voidaan luoda webtoken, jollä pääsee ohjelman muihin toimintoihin
                            console.log('Kirjautuminen onnistui');
                            const token=genToken({cardnumber: request.body.cardnumber});
                            response.send(token);
                        } else {
                            console.log('Väärä PIN');
                            response.send(false);
                        }
                    })
                } else {
                    console.log('Korttia ei ole');
                    response.send(false);
                }
            } 
        })
    } else {
        console.log('Kortti tai PIN puuttuu');
        response.send(false);
    }
});

function genToken(value){
    return jwt.sign(value, process.env.MY_TOKEN, {expiresIn:'300s'});
}

module.exports=router;