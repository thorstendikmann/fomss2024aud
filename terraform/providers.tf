terraform {
  required_providers {
    aws = {
      source = "hashicorp/aws"
    }
  }
}

# https://docs.aws.amazon.com/de_de/AWSEC2/latest/UserGuide/using-regions-availability-zones.html
provider "aws" {
  #  region                   = "us-west-2"
  region                   = "eu-central-1"
  shared_credentials_files = ["~/.aws/credentials"]
  profile                  = "fom"
}