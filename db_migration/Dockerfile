FROM python:3.12-alpine

ENV LANG C.UTF-8
ENV PYTHONUNBUFFERED=1

RUN apk update && \
    apk add --virtual build-deps gcc g++ musl-dev && \
    apk add postgresql-dev bash && \
    apk add --no-cache libpq

RUN mkdir -p /src/app
WORKDIR /src/app

COPY requirements.txt /src/app/
COPY wait-for.sh /bin/wait-for
RUN chmod +x /bin/wait-for

RUN pip3 install --no-cache-dir -r requirements.txt

CMD ["python"]
