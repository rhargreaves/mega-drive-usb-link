FROM rhargreaves/gendev:latest
RUN apt-get -y update && \
	apt-get -y install \
		build-essential \
		cmake
