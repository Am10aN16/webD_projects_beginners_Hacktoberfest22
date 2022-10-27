uploadJsonToS3(json, name, bucketName) {
       
        return new Promise(async(resolve, reject) => {
            var params = {
                Bucket: bucketName,
                Key: name,
            };
            let fileBuffer = new Buffer.from(JSON.stringify(json));
            params.Body = fileBuffer;
    
            s3.upload(params, function(err, resp) {
                if (err) {
                    reject(err)
                } else {
                    resolve(resp)
                }
            });
        })
    }
