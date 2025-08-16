# %%
import boto3

# Retrieve the list of existing buckets
s3 = boto3.client('s3')
response = s3.list_buckets()

# Output the bucket names
print('Existing buckets:')

for bucket in response['Buckets']:
    print(f'  {bucket["Name"]}')
# %%
with open("our-wedding.jpg", "rb") as file:
    s3.upload_fileobj(
        file,
        "aws-storage-events",
        "wedding-joaoemaria/our-wedding.jpg",
        ExtraArgs={
            "ContentType": "image/jpeg",
        }
    )
