#!/bin/bash

# Point to your tool and PDK installations
export OPENLANE_ROOT=/mnt/data1/DV/tools/openlane/OpenLane
export PDK_ROOT=/home/alhussein/.ciel
# export PWD="/project"
export PWD=$(pwd)

# Get the exact Docker image tag your OpenLane installation uses
IMAGE_NAME="ghcr.io/the-openroad-project/openlane:ff5509f65b17bfa4068d5336495ab1718987ff69-amd64"

# Run the Docker container, mounting your project as an external volume
docker run --rm \
  -e PWD=/project \
  -v $OPENLANE_ROOT:/openlane \
  -v $PDK_ROOT:$PDK_ROOT \
  -v $(pwd):/project \
  -e PDK_ROOT=$PDK_ROOT \
  -e PDK=sky130A \
  -u $(id -u):$(id -g) \
  $IMAGE_NAME \
  /openlane/flow.tcl -design /project