#!/usr/bin/env bash

xhost +local:docker
docker compose -f docker-compose.yml down
docker compose -f docker-compose.yml up