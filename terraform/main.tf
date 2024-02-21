# https://registry.terraform.io/providers/hashicorp/aws/latest/docs/resources/vpc
resource "aws_vpc" "fom_vpc" {
  cidr_block       = "10.123.0.0/16"
  instance_tenancy = "default"

  enable_dns_support   = true
  enable_dns_hostnames = true

  tags = {
    Name = "fom_vpc"
  }
}

resource "aws_subnet" "fom_public_subnet" {
  vpc_id                  = aws_vpc.fom_vpc.id
  cidr_block              = "10.123.1.0/24"
  map_public_ip_on_launch = true
  availability_zone       = "eu-central-1a"

  tags = {
    Name = "fom_public_subnet"
  }
}

resource "aws_internet_gateway" "fom_inet_gw" {
  vpc_id = aws_vpc.fom_vpc.id

  tags = {
    Name = "fom_inet_gw"
  }
}

resource "aws_route_table" "fom_public_rt" {
  vpc_id = aws_vpc.fom_vpc.id

  tags = {
    Name = "fom_public_rt"
  }

}

resource "aws_route" "fom_public_rt" {
  route_table_id         = aws_route_table.fom_public_rt.id
  destination_cidr_block = "0.0.0.0/0"
  gateway_id             = aws_internet_gateway.fom_inet_gw.id
}

resource "aws_route_table_association" "fom_public_a" {
  subnet_id      = aws_subnet.fom_public_subnet.id
  route_table_id = aws_route_table.fom_public_rt.id
}

resource "aws_security_group" "fom_allow_ssh" {
  name        = "fom_allow_ssh"
  description = "Allow SSH inbound traffic and all outbound traffic"
  vpc_id      = aws_vpc.fom_vpc.id

  # Ping - ICMP Echo
  ingress {
    from_port   = 8
    to_port     = 0
    protocol    = "icmp"
    cidr_blocks = ["0.0.0.0/0"]
  }

  # SSH
  ingress {
    from_port   = 22
    to_port     = 22
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }

  # Doc Server
  ingress {
    from_port   = 8080
    to_port     = 8080
    protocol    = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }

  egress {
    from_port   = 0
    to_port     = 0
    protocol    = "-1"
    cidr_blocks = ["0.0.0.0/0"]
  }
}

resource "aws_key_pair" "fom_key" {
  key_name   = "fom-key"
  public_key = file("~/.ssh/id_ed25519.pub")
}

resource "aws_instance" "fom_aud" {
  ami                    = data.aws_ami.fom_aud_ami.id
  instance_type          = "t2.micro"
  key_name               = aws_key_pair.fom_key.key_name
  vpc_security_group_ids = [aws_security_group.fom_allow_ssh.id]
  subnet_id              = aws_subnet.fom_public_subnet.id
  user_data              = file("userdata.tpl")

  root_block_device {
    volume_size = 10
  }

  tags = {
    Name = "fom_aud"
  }

}

#output "instance_private_ip_addr" {
#  value = aws_instance.fom_aud.private_ip
#}
output "instance_public_ip_addr" {
  value = aws_instance.fom_aud.public_ip
}