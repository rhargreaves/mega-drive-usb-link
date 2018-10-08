FROM debian:stretch
RUN apt-get -y update && \
	apt-get -y install \
		build-essential \
		cmake
